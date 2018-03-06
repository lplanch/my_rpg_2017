/*
** EPITECH PROJECT, 2018
** graphic
** File description:
** move_rect
*/

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
	rect.left += offset;
	if (rect.left == max_value)
		rect.left = 0;
	return (rect);
}
