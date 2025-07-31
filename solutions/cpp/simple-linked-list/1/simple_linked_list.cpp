#include "simple_linked_list.h"

#include <stdexcept>
#include <iostream>

namespace simple_linked_list {

size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
		auto new_element = std::make_unique<Element>(entry);
		new_element->next = std::move(head);
		head = std::move(new_element);
		current_size++;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
		int data = head->data;
		head = std::move(head->next);
		current_size--;
    return data;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
		auto current = std::move(head);
		std::unique_ptr<Element> prev = nullptr, next = nullptr;
		
		while (current){
			next = std::move(current->next);
			current->next = std::move(prev);

			prev = std::move(current);
			current = std::move(next);
		}

		head = std::move(prev);
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction

		// This is handled by the smart pointers implementation
}

}  // namespace simple_linked_list
