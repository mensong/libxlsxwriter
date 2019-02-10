/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2019, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_workbook  *workbook  = new_workbook("test_rich_string05.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    lxw_format *bold = workbook_add_format(workbook);
    lxw_format *italic = workbook_add_format(workbook);

    format_set_bold(bold);
    format_set_italic(italic);

    worksheet_set_column(worksheet, 0, 0, 30, NULL);

    worksheet_write_string(worksheet, CELL("A1"), "Foo", bold);
    worksheet_write_string(worksheet, CELL("A2"), "Bar", italic);

    lxw_rich_string_tuple fragment1 = {.format = NULL,   .string = "This is "};
    lxw_rich_string_tuple fragment2 = {.format = bold,   .string = "bold"};
    lxw_rich_string_tuple fragment3 = {.format = NULL,   .string = " and this is "};
    lxw_rich_string_tuple fragment4 = {.format = italic, .string = "italic"};

    lxw_rich_string_tuple *rich_strings[] = {&fragment1, &fragment2, &fragment3, &fragment4, NULL};
    worksheet_write_rich_string(worksheet, CELL("A3"), rich_strings, NULL);

    return workbook_close(workbook);
}