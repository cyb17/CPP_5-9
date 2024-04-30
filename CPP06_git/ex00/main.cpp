/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:53:27 by yachen            #+#    #+#             */
/*   Updated: 2024/04/30 17:20:24 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator>

int	main()
{
	double nb = 42;
	// char	c = static_cast<char>(nb);
	float	f = static_cast<float>(nb);
	// double	d = static_cast<double>(nb);
	std::cout << f << '\n';
}


// inputs : 

// null string
// abcdfgdhj
// fgjsdh678
// ^&*(*)
// 46738
// 0.0f
// 0.0
// space
// space42

// literal type:

// string -> impossible 
// nb : 32-126 (char displayable)

#include <cctype>
#include <cstdlib>
#include <climits>

