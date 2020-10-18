#ifndef SLW_VARIANT_NUMBER_HPP
#define SLW_VARIANT_NUMBER_HPP

#include "slw/variant/variant.hpp"

namespace slw {

template<>
struct variant<slw::number_t> {
    typedef slw::number_t expected_value_type;
    static constexpr type_e internal_value_type = TNUMBER;

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    explicit variant(slw::shared_state state);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    variant(slw::shared_state, const slw::string_t &name);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    variant(slw::shared_state, const slw::reference &ref);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    variant(slw::shared_state, slw::int_t idx);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    variant(slw::shared_state, slw::variant<expected_value_type> &);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::variant
    ////////////////////////////////////////////////////////////
    variant(const slw::reference &);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::operator *
    ////////////////////////////////////////////////////////////
    expected_value_type operator *() const;

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::operator =
    ////////////////////////////////////////////////////////////
    variant<expected_value_type> &operator =(const expected_value_type &);

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::operator ==
    ////////////////////////////////////////////////////////////
    bool operator ==(const expected_value_type &&) const;
    bool operator ==(const expected_value_type &) const;
    bool operator ==(const variant<expected_value_type> &) const;
    bool operator ==(const variant<expected_value_type> &&) const;

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::operator !=
    ////////////////////////////////////////////////////////////
    bool operator !=(const expected_value_type &&) const;
    bool operator !=(const expected_value_type &) const;
    bool operator !=(const variant<expected_value_type> &) const;
    bool operator !=(const variant<expected_value_type> &&) const;

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::expected_value_type ()
    ////////////////////////////////////////////////////////////
    operator expected_value_type();

    ////////////////////////////////////////////////////////////
    /// \see slw::variant::get
    ////////////////////////////////////////////////////////////
    slw::reference get();

private:

    ////////////////////////////////////////////////////////////
    /// \brief The Lua state
    ////////////////////////////////////////////////////////////
    slw::shared_state M_state;

    ////////////////////////////////////////////////////////////
    /// \brief The object reference
    ////////////////////////////////////////////////////////////
    slw::reference M_ref;
};

typedef variant<slw::number_t> number;

} //namespace slw

#endif //SLW_VARIANT_NUMBER_HPP
