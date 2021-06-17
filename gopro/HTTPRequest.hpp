#include <iostream>
#include <curl/curl.h>
#include <string>

class HTTPRequest {
    std::string m_url;
    public:
        HTTPRequest(std::string url);
        std::string execute();
    private:
        static size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data);
};
