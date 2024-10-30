#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Function to write response data into a string
size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data) {
    strncat(data, (char *)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    char data[1000] = {0}; // Buffer to store response data

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");

        // Set write callback to store the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Print the response data
            printf("Response:\n%s\n", data);
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    return 0;
}
