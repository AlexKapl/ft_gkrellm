/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kernel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:31:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 20:31:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KERNEL_HPP
# define KERNEL_HPP

# include "ft_gkrellm.h"


class Kernel {

public:

	static std::string & getKernelInfoByName(const std::string & name);

	static std::string & getUserName();

private:

	Kernel();

	Kernel(Kernel const &copy);

	~Kernel();

	Kernel &operator=(Kernel const &assign);

};


#endif
