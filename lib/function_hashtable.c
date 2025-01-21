#include "./function_hashtable.h"
#include <string.h>
#include <stdio.h>

#define TABLE_SIZE 100

unsigned int function_hash(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = 31 * hash + key[i];
    }
    return hash % TABLE_SIZE;
}

function_table *function_table_create() {
    function_table *table = malloc(sizeof(function_table));
    table->entries = malloc(sizeof(function_entry *) * TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

function_entry *function_table_pair(const char *id, const char *return_type, char *parameters) {
    function_entry *entry = malloc(sizeof(function_entry));
    entry->key = strdup(id);
    entry->return_type = strdup(return_type);
    entry->parameters = strdup(parameters);
    entry->next = NULL;
    return entry;
}

void function_table_set(function_table *table, const char *id, const char *return_type, char *parameters) {
    unsigned int index = function_hash(id);
    function_entry *entry = table->entries[index];

    while (entry) {
        if (strcmp(entry->key, id) == 0) {
            free(entry->return_type);
            entry->return_type = strdup(return_type);
            free(entry->parameters);

            entry->parameters = strdup(parameters);
            return;
        }
        entry = entry->next;
    }

    function_entry *new_entry = function_table_pair(id, return_type, parameters);
    new_entry->next = table->entries[index];
    table->entries[index] = new_entry;
}

function_entry *function_table_get(function_table *table, const char *id) {
    unsigned int index = function_hash(id);
    function_entry *entry = table->entries[index];
    while (entry) {
        if (strcmp(entry->key, id) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

void function_table_free(function_table *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        function_entry *entry = table->entries[i];
        while (entry) {
            function_entry *temp = entry;
            free(entry->key);
            free(entry->return_type);
            free(entry->parameters);
            entry = entry->next;
            free(temp);
        }
    }
    free(table->entries);
    free(table);
}
