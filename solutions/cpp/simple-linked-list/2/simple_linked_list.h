#if !defined(SIMPLE_LINKED_LIST_H)
#define SIMPLE_LINKED_LIST_H

#include <cstddef>
#include <memory>

namespace simple_linked_list {

class List {
   public:
    List() noexcept = default;
    ~List();

    // Moving and copying is not needed to solve the exercise.
    // If you want to change these, make sure to correctly
    // free / move / copy the allocated resources.
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;

    size_t size() const noexcept;
    void push(int entry);
    int pop() noexcept;
    void reverse() noexcept;

   private:
    struct Element {
        Element(int data) : data{data} {};
        int data{};
        std::unique_ptr<Element> next{nullptr};
    };

    std::unique_ptr<Element> head{nullptr};
    size_t current_size{0};
};

}  // namespace simple_linked_list

#endif
