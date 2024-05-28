/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/28 18:45:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main()
{
	BitcoinExchange	bitcoin( "./teste/.csv" );
	
	bitcoin.readFile();
	// bitcoin.analyzeFileContent();
	
	return 0;
}