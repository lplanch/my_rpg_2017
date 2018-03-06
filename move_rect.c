/*
** EPITECH PROJECT, 2018
** graphic
** File description:
** move_rect
*/

void move_rect(/*rect*/, int offset, int max_value)
{
	rect.left += offset;
	if (rect.left == max_value)
		rect.left = 0;
}
