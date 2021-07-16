//
// Created by neko on 2021/7/14.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "../leetcode_utils.h"

/*
 * https://leetcode-cn.com/problems/simplify-path/
 * basic ops.
 *
 * It looks very easy but there are a few things that
 * should be careful. First, /., /./, /.., /../ are all
 * equivalent to /, but /..., /.../ and so on are not. When
 * the number of dots are greater than 3, the part of the
 * path must be a filename. Second, . may not necessarily
 * means the current dir, and .. may not necessarily
 * means going to the previous level of the path. For example,
 * /3. and /3.. are two simplified paths. The correct way to judge
 * if . corresponds to the current dir: "/./" or "/.\0". And
 * the correct way to judge if .. corresponds to going to the
 * previous level of the path: "/../" or "/..\0".
 * When checking if the path ends with a /, see if the path only
 * contains a /. If so it is valid and the / needs not to be
 * removed.
 * O(n), O(n).
 *
 * 1. Remember to check if top - 1 is greater than 0
 * when writing stack[top - 1].
 * 2. When the stack is a string, it should end with a \0.
 * That is, assign the \0 to the end.
 */
char *simplifyPath71(char *path) {
    char *stack = malloc(sizeof(char) * ((int) strlen(path) + 1));
    int top = 0;
    // Pushes the root.
    stack[top++] = '/';
    path++;

    while (*path != '\0') {
        if (stack[top - 1] == '/'
            && *path == '/') {
            // Ignores the second '/'.
            path++;
            continue;
        }

        if (stack[top - 1] == '/'
            && *path == '.'
            && (*(path + 1) == '/' || *(path + 1) == '\0')) {
            // Ignores the '/' or '\0'.
            path++;
            continue;
        }

        if (stack[top - 1] == '/'
            && *path == '.'
            && *(path + 1) == '.'
            && (*(path + 2) == '/' || *(path + 2) == '\0')) {
            // Ignores the second '.'.
            path++;
            // Ignores the '/' or '\0'.
            path++;

            // Returns to the previous level
            // of the path.

            // Pops the '/'.
            top--;
            if (top == 0) {
                // Already the root.
                top++;
            } else {
                // Returns to the previous level
                // of the path.
                while (stack[top - 1] != '/') {
                    top--;
                }
            }

            continue;
        }

        // Push.
        stack[top++] = *path;
        path++;
    }

    // The end of the string should be '\0'.
    stack[top] = '\0';

    // Checks if the path ends with '/'.
    if (stack[top - 1] == '/') {
        if (top - 1 == 0) {
            // Root.
        } else {
            stack[top - 1] = '\0';
        }
    }

    return stack;
}

//int main() {
//    char strings[][10000] = {
//            "/home/",
//            "/../",
//            "/home//foo/",
//            "/a/./b/../../c/",
//            "/",
//
//            "/.",
//            "/./",
//            "/..",
//            "/../",
//            "/...",
//            "/.../",
//            "/....",
//            "/..../",
//            "/.....",
//            "/...../",
//            "/abc/...",
//            "/a/../../b/../c//.//",
//            "/1../",
//            "/1./",
//            "/hello../world"
//    };
//    for (int i = 0; i < 20; i++) {
//        char *result = simplifyPath71(strings[i]);
//        printCharArray(result);
//    }
//}