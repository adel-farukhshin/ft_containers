//
// Created by adelfarukhshin on 29/01/23.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>

namespace ft {

	template <typename T>
	class RandomAccessIterator;

	template <class Iterator>
	class ReverseIterator;

	template <typename T, class Alloc = std::allocator<T> >
		class vector {
		public:

			// -------------------------- Aliases -------------------------- //

			typedef T											value_type;
			typedef Alloc										allocator_type;
//			typedef typename allocator_type::reference			reference;
//			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
//			typedef RandomAccessIterator<value_type>			iterator;
//			typedef RandomAccessIterator<const value_type>		const_iterator;
//			typedef ReverseIterator<iterator>					reverse_iterator;
//			typedef ReverseIterator<const_iterator>				const_reverse_iterator;
//			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef unsigned long								size_type;

			// -------------------------- Attributes -------------------------- //

		private:
			allocator_type	alloc_;
			pointer			arr_;
			size_type		capacity_;
			size_type		size_;

			// ------------------------- Coplien form ------------------------- //

		public:
			// Default
			explicit vector(const allocator_type& alloc = allocator_type())
			:
				alloc_(alloc),
				arr_(0),
				capacity_(0),
				size_(0)
			{
			};

			//Fill
			//explicit vector (size_type n, const value_type& val = value_type(),
			// 				const allocator_type& alloc = allocator_type());
			//
			//Range
			//template <class InputIterator> vector (InputIterator first, InputIterator last,
			// 										const allocator_type& alloc = allocator_type());
			//
			//Copy
			vector (const vector& x)
			:
				arr_(x.alloc_.allocate(x.capacity_)),
				alloc_(x.alloc_),
				capacity_(x.capacity_),
				size_(x.size_)
			{
				for (size_type i = 0; i < size_; ++i) {
					alloc_.construct(&arr_[i], x.arr_[i]);
				}
			};

			// Destructor
			virtual ~vector() { // TODO: refactor with iterators
				for (size_type i = 0; i < size_; ++i) {
					alloc_.destroy(&arr_[i]);
				}
				alloc_.deallocate(arr_, capacity_);
			}

			vector& operator= (const vector& x) {

			}

			// -------------------------- Iterators -------------------------- //

//			iterator begin() {return iterator(arr_);}
//
//			const_iterator begin() const {return const_iterator(arr_);};
//
//			iterator end() {return iterator(arr_ + size_);};
//
//			const_iterator end() const {return const_iterator(arr_ + size_);};

			// -------------------------- Capacity -------------------------- //

			size_type size() const {return size_;}

			// max_size

			void resize (size_type n, value_type val = value_type()) {
				if (n == size_ || n < 0) {return;}

				if (n < size_) {
					for (size_type i = n; i < size_; ++i) {
						alloc_.destroy(&arr_[i]);
					}
					return;
				}

				reserve(n);
				size_ = n;
			}

			size_type capacity() const {return capacity_;};

			bool empty() const {return size_ == 0 ? true : false;};

			void reserve (size_type n) {
				if (capacity_ >= n)
					return;

				pointer new_arr = alloc_.allocate(n);

				for (size_type i = 0; i < size_; ++i) {
					alloc_.construct(&new_arr[i], arr_[i]);
				} // TODO: check for exception - free new_arr

				for (size_type i = 0; i < size_; ++i) {
					alloc_.destroy(&arr_[i]);
				}

				alloc_.deallocate(arr_, size_);

				arr_ = new_arr;
				capacity_ = n;
			}

			// shrink_to_fit

			// -------------------------- Modifiers -------------------------- //

			// assign

			void push_back (const value_type& val) {

			}

			// pop_back

			// insert

			// erase

			// swap

			// clear

			// emplace

			// emplace_back
		};

	template <typename T>
	class RandomAccessIterator {

	};

	template <class Iterator>
	class ReverseIterator {

	};

}


#endif //VECTOR_HPP
