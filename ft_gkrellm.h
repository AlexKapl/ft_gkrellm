/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gkrellm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:06:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 19:06:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <vector>
# include <ncurses.h>
# include <panel.h>
# include <pwd.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <mach/mach_types.h>
# include <mach/mach_host.h>

# define THEMES_NUM 3
# define BACK 4
# define BORDER 5
# define TITLE 6
# define HIGHLIGHT 7
# define COLOR_BACK COLOR_BLUE
# define COLOR_BORDER COLOR_MAGENTA
# define COLOR_TITLE COLOR_YELLOW
# define ENTER 10
# define PAUSE 32
# define BACKSPACE 127
# define TAB 9

#endif
