/*
** EPITECH PROJECT, 2019
** IO unit tests
** File description:
** UT: Filling flag fields in format argument struct
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "printf/argparse.h"
#include "printf/fstruct.h"

Test(get_flags, all_cases)
{
    finfo_t info = {0};
    str_t format = "# +'0o";

    get_flags(&info, &format);
    cr_expect_eq(*format, 'o');
    cr_expect(info.alt);
    cr_expect(info.space);
    cr_expect(info.showsign);
    cr_expect(info.group);
    cr_expect_not(info.left);
    cr_expect_eq(info.padchar, '0');
    format = "-";
    get_flags(&info, &format);
    cr_expect(info.left);
    cr_expect_eq(info.padchar, ' ');
}