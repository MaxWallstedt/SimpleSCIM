# Copyright © 2017-2018  Max Wällstedt <max.wallstedt@gmail.com>
#
# This file is part of SimpleSCIM.
#
# SimpleSCIM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# SimpleSCIM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with SimpleSCIM.  If not, see <http://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -g -pedantic -Wall -Wextra -Werror `pkg-config --cflags json-c`
LDFLAGS = -lldap -llber `pkg-config --libs json-c` -lcurl
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes

all: SimpleSCIM

SimpleSCIM: \
	uthash.h \
	simplescim_main.o \
	simplescim_error_string.o \
	simplescim_arbval.o \
	simplescim_arbval_list.o \
	simplescim_user.o \
	simplescim_user_list.o \
	simplescim_config_file.o \
	simplescim_config_file_open.o \
	simplescim_config_file_to_string.o \
	simplescim_config_file_parser.o \
	simplescim_ldap.o \
	simplescim_ldap_attrs_parser.o \
	simplescim_cache_file.o \
	simplescim_scim.o \
	simplescim_scim_json.o \
	simplescim_scim_send.o
	@echo "LINK $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

SimpleSCIM_simulate: \
	uthash.h \
	simplescim_main.o \
	simplescim_error_string.o \
	simplescim_arbval.o \
	simplescim_arbval_list.o \
	simplescim_user.o \
	simplescim_user_list.o \
	simplescim_config_file.o \
	simplescim_config_file_open.o \
	simplescim_config_file_to_string.o \
	simplescim_config_file_parser.o \
	simplescim_ldap_simulate.o \
	simplescim_ldap_attrs_parser.o \
	simplescim_cache_file.o \
	simplescim_scim.o \
	simplescim_scim_json.o \
	simplescim_scim_send.o
	@echo "LINK $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

simplescim_cache_file_print: \
	uthash.h \
	simplescim_cache_file_print.o \
	simplescim_error_string.o \
	simplescim_arbval.o \
	simplescim_arbval_list.o \
	simplescim_user.o \
	simplescim_user_list.o \
	simplescim_config_file.o \
	simplescim_config_file_open.o \
	simplescim_config_file_to_string.o \
	simplescim_config_file_parser.o \
	simplescim_cache_file.o
	@echo "LINK $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

uthash.h:
	curl https://raw.githubusercontent.com/troydhanson/uthash/master/src/uthash.h > uthash.h

simplescim_main.o: \
	simplescim_main.c \
	simplescim_error_string.h \
	simplescim_user_list.h \
	simplescim_config_file.h \
	simplescim_ldap.h \
	simplescim_cache_file.h \
	simplescim_scim.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_error_string.o: \
	simplescim_error_string.c \
	simplescim_error_string.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_arbval.o: \
	simplescim_arbval.c \
	simplescim_arbval.h \
	simplescim_error_string.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_arbval_list.o: \
	simplescim_arbval_list.c \
	simplescim_arbval_list.h \
	simplescim_error_string.h \
	simplescim_arbval.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_user.o: \
	simplescim_user.c \
	simplescim_user.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_config_file.h \
	uthash.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_user_list.o: \
	simplescim_user_list.c \
	simplescim_user_list.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_user.h \
	uthash.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_config_file.o: \
	simplescim_config_file.c \
	simplescim_config_file.h \
	simplescim_error_string.h \
	simplescim_config_file_open.h \
	simplescim_config_file_to_string.h \
	simplescim_config_file_parser.h \
	uthash.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_config_file_open.o: \
	simplescim_config_file_open.c \
	simplescim_config_file_open.h \
	simplescim_error_string.h \
	simplescim_config_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_config_file_to_string.o: \
	simplescim_config_file_to_string.c \
	simplescim_config_file_to_string.h \
	simplescim_error_string.h \
	simplescim_config_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_config_file_parser.o: \
	simplescim_config_file_parser.c \
	simplescim_config_file_parser.h \
	simplescim_error_string.h \
	simplescim_config_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_ldap.o: \
	simplescim_ldap.c \
	simplescim_ldap.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h \
	simplescim_user_list.h \
	simplescim_config_file.h \
	simplescim_ldap_attrs_parser.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_ldap_simulate.o: \
	simplescim_ldap_simulate.c \
	simplescim_ldap.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h \
	simplescim_user_list.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_ldap_attrs_parser.o: \
	simplescim_ldap_attrs_parser.c \
	simplescim_ldap_attrs_parser.h \
	simplescim_error_string.h \
	simplescim_config_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_cache_file.o: \
	simplescim_cache_file.c \
	simplescim_cache_file.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h \
	simplescim_user_list.h \
	simplescim_config_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_cache_file_print.o: \
	simplescim_cache_file_print.c \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h \
	simplescim_user_list.h \
	simplescim_cache_file.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_scim.o: \
	simplescim_scim.c \
	simplescim_scim.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h \
	simplescim_user_list.h \
	simplescim_cache_file.h \
	simplescim_scim_json.h \
	simplescim_scim_send.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_scim_json.o: \
	simplescim_scim_json.c \
	simplescim_scim_json.h \
	simplescim_error_string.h \
	simplescim_arbval.h \
	simplescim_arbval_list.h \
	simplescim_user.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

simplescim_scim_send.o: \
	simplescim_scim_send.c \
	simplescim_scim_send.h \
	simplescim_error_string.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

#############################################
#                   Tests                   #
#############################################

tests: \
	test_simplescim_arbval

run_test: \
	run_test_simplescim_arbval

run_tests_valgrind: \
	valgrind_test_simplescim_arbval

#############################################
#          test_simplescim_arbval           #
#############################################

run_test_simplescim_arbval: \
	test_simplescim_arbval
	@echo "RUNNING $<"
	@./$<

valgrind_test_simplescim_arbval: \
	test_simplescim_arbval
	@echo "VALGRIND $<"
	@$(VALGRIND) ./$<

test_simplescim_arbval: \
	test_simplescim_arbval.o \
	simplescim_error_string.o \
	simplescim_arbval.o
	@echo "LINK $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_simplescim_arbval.o: \
	test_simplescim_arbval.c \
	simplescim_arbval.h
	@echo "CC $<"
	@$(CC) -c $(CFLAGS) -o $@ $<

#############################################
#                 Clean up                  #
#############################################

.PHONY: \
	clean_object \
	clean_test_object \
	clean_executable \
	clean_test_executable \
	clean

clean_object:
	rm -f simplescim_main.o
	rm -f simplescim_error_string.o
	rm -f simplescim_arbval.o
	rm -f simplescim_arbval_list.o
	rm -f simplescim_user.o
	rm -f simplescim_user_list.o
	rm -f simplescim_config_file.o
	rm -f simplescim_config_file_open.o
	rm -f simplescim_config_file_to_string.o
	rm -f simplescim_config_file_parser.o
	rm -f simplescim_ldap.o
	rm -f simplescim_ldap_simulate.o
	rm -f simplescim_ldap_attrs_parser.o
	rm -f simplescim_cache_file.o
	rm -f simplescim_cache_file_print.o
	rm -f simplescim_scim.o
	rm -f simplescim_scim_json.o
	rm -f simplescim_scim_send.o

clean_test_object:
	rm -f test_simplescim_arbval.o

clean_executable:
	rm -f SimpleSCIM
	rm -f SimpleSCIM_simulate
	rm -f simplescim_cache_file_print

clean_test_executable:
	rm -f test_simplescim_arbval

clean: \
	clean_object \
	clean_test_object \
	clean_executable \
	clean_test_executable
	rm -f uthash.h
