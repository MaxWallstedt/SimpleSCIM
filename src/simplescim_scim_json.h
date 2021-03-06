/**
 * Copyright © 2017-2018  Max Wällstedt <max.wallstedt@gmail.com>
 *
 * This file is part of SimpleSCIM.
 *
 * SimpleSCIM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SimpleSCIM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with SimpleSCIM.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SIMPLESCIM_SCIM_JSON_H
#define SIMPLESCIM_SCIM_JSON_H

#include "simplescim_user.h"

/**
 * Parses the input JSON template string 'json' and
 * replaces specified values with values from 'user'.
 * On success, the parsed output JSON string is returned.
 * On error, NULL is returned and simplescim_error_string
 * is set to an appropriate error message.
 */
char *simplescim_scim_json_parse(
	const char *json,
	const struct simplescim_user *user
);

#endif
