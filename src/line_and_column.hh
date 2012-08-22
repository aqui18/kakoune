#ifndef line_and_column_hh_INCLUDED
#define line_and_column_hh_INCLUDED

#include "units.hh"

namespace Kakoune
{

template<typename EffectiveType>
struct LineAndColumn
{
    LineCount line;
    int column;

    LineAndColumn(LineCount line = 0, int column = 0)
        : line(line), column(column) {}

    EffectiveType operator+(const EffectiveType& other) const
    {
        return EffectiveType(line + other.line, column + other.column);
    }

    EffectiveType& operator+=(const EffectiveType& other)
    {
        line   += other.line;
        column += other.column;
        return *static_cast<EffectiveType*>(this);
    }

    EffectiveType operator-(const EffectiveType& other) const
    {
        return EffectiveType(line - other.line, column - other.column);
    }

    EffectiveType& operator-=(const EffectiveType& other)
    {
        line   -= other.line;
        column -= other.column;
        return *static_cast<EffectiveType*>(this);
    }

    bool operator< (const EffectiveType& other) const
    {
        if (line != other.line)
            return line < other.line;
        return column < other.column;
    }

    bool operator<= (const EffectiveType& other) const
    {
        if (line != other.line)
            return line < other.line;
        return column <= other.column;
    }

    bool operator> (const EffectiveType& other) const
    {
        if (line != other.line)
            return line > other.line;
        return column > other.column;
    }

    bool operator>= (const EffectiveType& other) const
    {
        if (line != other.line)
            return line > other.line;
        return column >= other.column;
    }

    bool operator== (const EffectiveType& other) const
    {
        return line == other.line and column == other.column;
    }

    bool operator!= (const EffectiveType& other) const
    {
        return line != other.line or column != other.column;
    }
};

}

#endif // line_and_column_hh_INCLUDED
