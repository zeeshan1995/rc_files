
template<typename Object, typename Predicate>
constexpr bool conjunction(Object && object, Predicate && p, Predicates... ps)
{
    return p(object);
}

template<typename Object, typename Predicate, typename... Predicates>
constexpr bool conjunction(Object && object, Predicate && p, Predicates... ps)
{
    return (p(object) and conjunction(object, ps...);
}
