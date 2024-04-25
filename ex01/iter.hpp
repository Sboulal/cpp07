/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboulal <saboulal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:47:08 by saboulal          #+#    #+#             */
/*   Updated: 2024/04/25 22:20:44 by saboulal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
template <typename T>
void iter(T *array, size_t size, void (*func)(T const &))
{
    for (size_t i = 0; i < size; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}