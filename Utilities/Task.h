#pragma once

#include <string_view>
#include <string>
#include <memory>
#include <utility>

namespace CML {

    class ThreadPool;

    using task_id = unsigned long long;

    class Task {
    public:
        virtual ~Task() = default;

        enum class TaskStatus {
            Awaiting,
            Completed,
        };

        explicit Task(std::string_view description, std::shared_ptr<ThreadPool> pool = nullptr)
            : status_(TaskStatus::Awaiting), description_(description), id_(0), threadPool_(std::move(std::move(pool))) {
        }

        void send_signal();

        virtual void one_thread_method() = 0;

        [[nodiscard]] TaskStatus get_status() const { return status_; }
        void set_status(TaskStatus new_status) { status_ = new_status; }

        [[nodiscard]] task_id get_id() const { return id_; }

    protected:
        TaskStatus status_;
        std::string description_;
        task_id id_;

        std::shared_ptr<ThreadPool> threadPool_;

        void one_method_per_method();
    };

} // namespace CML
