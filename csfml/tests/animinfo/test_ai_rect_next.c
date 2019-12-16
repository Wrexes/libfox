/*
** EPITECH PROJECT, 2019
** csfml unit tests
** File description:
** test_ai_current_rect.c -- No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "fox_csfml.h"

animRect_create(testai0)
{
    {.top = 23, .left = 42, .height = 32, .width = 24},
    {.top = 10, .left = 20, .height = 30, .width = 40},
    __animRect_sentinel__
};

animRect_create(testai1)
{
    {.top = 10, .left = 20, .height = 30, .width = 40},
    {.top = 23, .left = 42, .height = 32, .width = 24},
    __animRect_sentinel__
};

static animRectTab_init(testai)
{
    animRect(testai0),
    animRect(testai1)
};

Test(ai_rect_next, regular_usage)
{
    struct animation_info ai = {
        .current = 0,
        .frame = 0,
        .rect = animRectTab(testai)
    };

    cr_expect_eq(ai_rect_next(&ai)->left, animRect(testai1)[0].left);
    cr_expect_eq(ai_rect_next(&ai)->top, animRect(testai1)[0].top);
    cr_expect_eq(ai_rect_next(&ai)->height, animRect(testai1)[0].height);
    cr_expect_eq(ai_rect_next(&ai)->width, animRect(testai1)[0].width);
    ai.current = 1;
    cr_expect_eq(ai_rect_next(&ai)->left, animRect(testai0)[0].left);
    cr_expect_eq(ai_rect_next(&ai)->top, animRect(testai0)[0].top);
    cr_expect_eq(ai_rect_next(&ai)->height, animRect(testai0)[0].height);
    cr_expect_eq(ai_rect_next(&ai)->width, animRect(testai0)[0].width);
}
