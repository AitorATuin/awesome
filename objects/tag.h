/*
 * tag.h - tag management header
 *
 * Copyright © 2007-2009 Julien Danjou <julien@danjou.info>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef AWESOME_OBJECTS_TAG_H
#define AWESOME_OBJECTS_TAG_H

#include "objects/ewindow.h"

/** Tag type */
struct tag
{
    LUA_OBJECT_HEADER
    /** Tag name */
    char *name;
    /** Screen */
    screen_t *screen;
    /** true if selected */
    bool selected;
    /** Windows in this tag */
    ewindow_array_t windows;
};

int tags_get_first_selected_index(screen_t *);
void tag_ewindow(lua_State *, int, int);
void untag_ewindow(lua_State *, int, int);
bool ewindow_is_tagged(ewindow_t *, tag_t *);
void tag_view_only_byindex(screen_t *, int);
void tag_append_to_screen(lua_State *, int, screen_t *);
void tag_remove_from_screen(tag_t *);
void tag_unref_simplified(tag_t **);

ARRAY_FUNCS(tag_t *, tag, tag_unref_simplified)

void tag_class_setup(lua_State *);

bool tag_get_selected(tag_t *);
char *tag_get_name(tag_t *);

lua_class_t tag_class;

#endif
// vim: filetype=c:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=80