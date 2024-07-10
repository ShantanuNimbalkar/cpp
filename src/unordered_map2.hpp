#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include <boost/unordered_map.hpp>

template <class K, class T, class H = boost::hash<K>, class P = std::equal_to<K>, class A = std::allocator<std::pair<const K, T>>>
class unordered_multimap {
public:
    using key_type = K;
    using mapped_type = T;
    using value_type = std::pair<const K, T>;
    using hasher = H;
    using key_equal = P;
    using allocator_type = A;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<A>::pointer;
    using const_pointer = typename std::allocator_traits<A>::const_pointer;
    using iterator = typename boost::unordered_map<K, T, H, P, A>::iterator;
    using const_iterator = typename boost::unordered_map<K, T, H, P, A>::const_iterator;
    using size_type = typename boost::unordered_map<K, T, H, P, A>::size_type;
    using difference_type = typename boost::unordered_map<K, T, H, P, A>::difference_type;

    unordered_multimap() = default;

    // Duplicate block 1
template <class K, class T, class H, class P, class A>
template <typename H2, typename P2>
void unordered_multimap<K, T, H, P, A>::merge(
    boost::unordered_multimap<K, T, H2, P2, A>& source)
{
    while (!source.empty()) {
        insert(source.extract(source.begin()));
    }
}

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
template <class K, class T, class H, class P, class A>
template <typename H2, typename P2>
void unordered_multimap<K, T, H, P, A>::merge(
    boost::unordered_multimap<K, T, H2, P2, A>&& source)
{
    while (!source.empty()) {
        insert(source.extract(source.begin()));
    }
}
#endif

    // Duplicate block 2
template <class K, class T, class H, class P, class A>
template <typename H2, typename P2>
void unordered_multimap<K, T, H, P, A>::merge(
    boost::unordered_map<K, T, H2, P2, A>& source)
{
    while (!source.empty()) {
        insert(source.extract(source.begin()));
    }
}

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
template <class K, class T, class H, class P, class A>
template <typename H2, typename P2>
void unordered_multimap<K, T, H, P, A>::merge(
    boost::unordered_map<K, T, H2, P2, A>&& source)
{
    while (!source.empty()) {
        insert(source.extract(source.begin()));
    }
}
#endif

    // Insert function
    std::pair<iterator, bool> insert(const value_type& obj) {
        return table_.insert(obj);
    }

    // Extract function
    boost::unordered::node_handle<K, T, H, P, A> extract(const_iterator position) {
        return table_.extract(position);
    }

    // Other necessary functions...

private:
    boost::unordered_multimap<K, T, H, P, A> table_;
};

#endif // UNORDERED_MAP_HPP
