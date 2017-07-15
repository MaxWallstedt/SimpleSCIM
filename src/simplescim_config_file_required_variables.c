#include "simplescim_config_file_required_variables.h"

#include <stdio.h>
#include <string.h>

#include "simplescim_error_string.h"
#include "simplescim_config_file.h"

/**
 * A NULL-terminated list of variable names that must be present in a
 * configuration file. The order that the variable names appear in
 * this list is important since the lists and functions further down
 * in this file assumes that the order is consistent between lists.
 */
static const char *required_variables[] = {
	"ldap-uri",
	"ldap-who",
	"ldap-passwd",
	"ldap-base",
	"ldap-scope",
	"ldap-filter",
	"ldap-attrs",
	"ldap-attrsonly",
	"ldap-unique-identifier",
	NULL
};

/**
 * A NULL-terminated list of possible values for the variable
 * "ldap-scope".
 */
static const char *required_values_ldap_scope[] = {
	"BASE",
	"ONELEVEL",
	"SUBTREE",
	"CHILDREN",
	NULL
};

/**
 * A NULL-terminated list of possible values for boolean variables.
 */
static const char *required_values_boolean[] = {
	"TRUE",
	"FALSE",
	NULL
};

/**
 * A list of lists that contain all valid values of a specific
 * variable. The order is assumed to be the same as in
 * required_variables, i.e. if required_variables[n] = "variable",
 * and "variable" can have value "value1" or "value2",
 * required_values[n] will point to a list of strings containing
 * {"value1", "value2", NULL}. If "variable" can have any value,
 * required_values[n] will be NULL.
 */
static const char **required_values[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	required_values_ldap_scope,
	NULL,
	NULL,
	required_values_boolean,
	NULL
};

/**
 * Ensures that the required variables are present in
 * simplescim_config_file and have one of its predefined
 * values if such values exist.
 * On success, zero is returned. On error, -1 is returned
 * and 'simplescim_error_string' is set to an appropriate
 * error message.
 */
int simplescim_config_file_required_variables()
{
	size_t i, j;
	const char *var, *val;
	int offset;
	int err;

	for (i = 0; required_variables[i] != NULL; ++i) {
		/* Fetch required variable name */
		var = required_variables[i];

		/* Fetch the presence status
		   and value of the variable */
		err = simplescim_config_file_get(var, &val);

		if (err == -1) {
			sprintf(simplescim_error_string,
"%s: required variable \"%s\" is missing",
			        simplescim_config_file_name,
			        var);
			return -1;
		}

		if (required_values[i] == NULL) {
			/* Current required variable
			   can have any value */
			continue;
		}

		/* Current required variable must
		   have a value in required_values[i] */
		for (j = 0; required_values[i][j] != NULL; ++j) {
			if (strcmp(val, required_values[i][j]) == 0) {
				/* Found a match in
				   required_values[i] */
				break;
			}
		}

		if (required_values[i][j] != NULL) {
			/* Match was found, so
			   variable value is correct */
			continue;
		}

		/* No match was found, so current required
		   variable has an incorrect value */
		offset = sprintf(simplescim_error_string,
"%s: variable \"%s\" has invalid value \"%s\"\n"
"variable \"%s\" must have one of the following values:\n",
		                 simplescim_config_file_name,
		                 var,
		                 val,
		                 var);

		for (j = 0; required_values[i][j] != NULL; ++j) {
			offset += sprintf(
				simplescim_error_string + offset,
				" %s",
				required_values[i][j]
			);
		}

		return -1;
	}

	return 0;
}
