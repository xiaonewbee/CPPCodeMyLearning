std::transform(
    vec.begin(),vec.end(),vec_2.begin(),

)

template< class InputIt1, class InputIt2,
          class OutputIt, class BinaryOperation >
constexpr OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
                              OutputIt d_first, BinaryOperation binary_op );


template< class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
          class ForwardIt3, class BinaryOperation >
ForwardIt3 transform( ExecutionPolicy&& policy,
                      ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2,
                      ForwardIt3 d_first, BinaryOperation binary_op );


template< class InputIt, class OutputIt, class UnaryOperation >
constexpr OutputIt transform( InputIt first1, InputIt last1,
                              OutputIt d_first, UnaryOperation unary_op );

template< class ExecutionPolicy, class ForwardIt1,
          class ForwardIt2, class UnaryOperation >
ForwardIt2 transform( ExecutionPolicy&& policy,
                      ForwardIt1 first1, ForwardIt1 last1,
                      ForwardIt2 d_first, UnaryOperation unary_op );

/*
The std::execution namespace provides the following execution policies:

std::execution::seq - This is the default execution policy and specifies that the algorithm should execute sequentially.

std::execution::par - This execution policy specifies that the algorithm should execute in parallel. The standard library implementation may use multiple threads to execute the algorithm.

std::execution::par_unseq - This execution policy specifies that the algorithm should execute in parallel and the order of the output elements may not be the same as the order of the input elements. The standard library implementation may use multiple threads and vectorization to execute the algorithm.
*/