/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:35:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 16:35:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_gkrellm.h"

static void init() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	start_color();
	init_color(COLOR_MAGENTA, 441, 453, 455);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(BORDER, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(TITLE, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(BORDER));
	wborder(stdscr, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	attroff(COLOR_PAIR(BORDER));
	refresh();
}

int main() {

	init();
	while (1);
	return (0);
}
