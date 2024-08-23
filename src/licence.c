#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the response data
typedef struct {
    char *data;
    size_t size;
} MemoryBlock;

// Callback function to write data to the MemoryBlock structure
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    MemoryBlock *mem = (MemoryBlock *)userp;

    char *new_data = realloc(mem->data, mem->size + total_size + 1);
    if (new_data == NULL) {
        fprintf(stderr, "Failed to expand buffer.\n");
        return 0;
    }

    mem->data = new_data;
    memcpy(&(mem->data[mem->size]), contents, total_size);
    mem->size += total_size;
    mem->data[mem->size] = '\0'; // Null-terminate the string

    return total_size;
}

// Function to get license text from GitHub repository
char* get_license_text(const char *license_name) {
    CURL *curl;
    CURLcode res;
    char url[256];
    MemoryBlock memory = { .data = NULL, .size = 0 };

    // Map license names to their filenames
    // const char *license_file_map[] = {
    //     "Apache License 2.0", "Apache_License_2.0.txt",
    //     "Boost Software", "Boost_Software_License.txt",
    //     "GNU AFFERO GENERAL PUBLIC", "GNU_AFFERO_GENERAL_PUBLIC_LICENSE.txt",
    //     "GPLv3", "GPLv3.txt",
    //     "Unlicensed", "Unlicensed.txt",
    //     "BSD 2-Clause", "BSD_2-Clause.txt",
    //     "Creative Commons Zero v1.0 Universal", "Creative_Commons_Zero_v1.0_Universal.txt",
    //     "GNU LESSER GENERAL PUBLIC LICENSE Version 2.1", "GNU_LESSER_GENERAL_PUBLIC_LICENSE_Version_2.1.txt",
    //     "MIT", "MIT.txt",
    //     "BSD 3-Clause", "BSD_3-Clause.txt",
    //     "Eclipse Public License - v 2.0", "Eclipse_Public_License_v2.0.txt",
    //     "GPLv2", "GPLv2.txt",
    //     "Mozilla Public License Version 2.0", "Mozilla_Public_License_Version_2.0.txt"
    // };

    // // Find the filename corresponding to the license name
    // const char *filename = NULL;
    // for (int i = 0; i < sizeof(license_file_map) / sizeof(license_file_map[0]); i += 2) {
    //     if (strcmp(license_name, license_file_map[i]) == 0) {
    //         filename = license_file_map[i + 1];
    //         break;
    //     }
    // }

    // if (filename == NULL) {
    //     fprintf(stderr, "License \"%s\" not found.\n", license_name);
    //     return NULL;
    // }

    snprintf(url, sizeof(url), "https://raw.githubusercontent.com/KingVentrix007/CodeStarterFiles/main/%s", license_name);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &memory);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        free(memory.data);
        memory.data = NULL;
    }

    curl_easy_cleanup(curl);
    return memory.data;
}

char * get_license(const char *name) {
    const char *license_name = name;
    char *text = get_license_text(license_name);

    if (text) {
        // printf("License text:\n%s\n", text);
        return text;
        // free(text);
    }

    return 0;
}
