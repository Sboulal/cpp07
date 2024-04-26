/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboulal <saboulal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:23:22 by saboulal          #+#    #+#             */
/*   Updated: 2024/04/26 00:30:22 by saboulal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{
    private:
        T *m_array;
        unsigned int m_size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        ~Array();
        Array &operator=(Array const &src);
        T &operator[](unsigned int index);
        unsigned int size() const;
};


template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n)
{
}

template <typename T>
Array<T>::Array(Array const &src) : m_array(new T[src.m_size]), m_size(src.m_size)
{
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_array[i] = src.m_array[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] m_array;
}


template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        delete[] m_array;
        m_array = new T[src.m_size];
        m_size = src.m_size;
        for (unsigned int i = 0; i < m_size; i++)
        {
            m_array[i] = src.m_array[i];
        }
    }
    return *this;
}


template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_array[index];
}


template <typename T>
unsigned int Array<T>::size() const
{
    return m_size;
}

std::ostream &operator<<(std::ostream &out, Array<int> const &array)
{
    for (unsigned int i = 0; i < array.size(); i++)
    {
        out << array[i] << " ";
    }
    return out;
}