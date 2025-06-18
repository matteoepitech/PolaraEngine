/*
** EPITECH PROJECT, 2025
** samples/test/main
** File description:
** Test game
*/

#include "../include/polara.hpp"

using namespace PL::core;

/**
 * @brief Main function
 *
 * @param argc
 * @param argv[]
 *
 * @return 
 */
int main(int argc, char *argv[])
{
    window win(1280, 720, "Test program");

    while (win.should_close() == PL_FALSE) {
        printf("Running");
        win.poll_events();
    }
    return 0;
}
