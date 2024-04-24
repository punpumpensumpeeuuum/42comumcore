/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/24 11:58:30 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

extern char **environ; // Access to the environment variables

int main() {
    char **env = environ; // Assign the environ to a local variable

    // Iterate over the env array until reaching a NULL pointer
    while (*env != NULL) {
        printf("%s\n", *env); // Print each environment variable
        env++; // Move to the next environment variable
    }

    return 0;
}