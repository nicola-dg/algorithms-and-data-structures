
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public ClearableContainer{

private:
  // ...
protected:
  using Container::size;
public:

  // Destructor
  virtual ~Queue() = default;

  /* ************************************************************************ */

   // Copy assignment
  Queue<Data>& operator=(const Queue<Data>&) = delete; // Copy assignment of abstract types should not be possible.
  Queue<Data>& operator=(Queue<Data>&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Queue<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Queue<Data>&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Head() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Head() = 0; // (mutable version; concrete function must throw std::length_error when empty)
  virtual bool Dequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data& HeadNDequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Enqueue(const Data&) = 0; // Copy of the value
  virtual void Enqueue(Data&&) noexcept = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif