// Copyright Daniel Wallin 2006.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PARAMETER_AUX_PP_IMPL_ARGUMENT_PACK_HPP
#define BOOST_PARAMETER_AUX_PP_IMPL_ARGUMENT_PACK_HPP

#include <boost/parameter/aux_/pack/tag_keyword_arg.hpp>
#include <boost/parameter/aux_/pack/make_arg_list.hpp>
#include <boost/parameter/aux_/pack/make_items.hpp>
#include <boost/parameter/aux_/void.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/parameter/aux_/preprocessor/no_perfect_forwarding_begin.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

namespace boost { namespace parameter { namespace aux {

    template <
        typename Parameters
      , BOOST_PP_ENUM_BINARY_PARAMS(
            BOOST_PARAMETER_MAX_ARITY
          , typename A
          , = ::boost::parameter::void_ BOOST_PP_INTERCEPT
        )
    >
    struct argument_pack
    {
        typedef typename ::boost::parameter::aux::make_arg_list<
            typename BOOST_PARAMETER_build_arg_list(
                BOOST_PARAMETER_MAX_ARITY
              , ::boost::parameter::aux::make_items
              , typename Parameters::parameter_spec
              , A
            )::type
          , typename Parameters::deduced_list
          , ::boost::parameter::aux::tag_keyword_arg
          , ::boost::mpl::false_
        >::type result;
        typedef typename ::boost::mpl::first<result>::type type;
    };
}}} // namespace boost::parameter::aux

#include <boost/parameter/aux_/preprocessor/no_perfect_forwarding_end.hpp>
#endif  // include guard

