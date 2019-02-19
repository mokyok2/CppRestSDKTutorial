#include "pch.h"
#include <cpprest/http_client.h>


int main()
{
    web::http::client::http_client client(L"https://httpbin.org");
    for (int i = 0; i < 1000; ++i)
    {
        web::json::value req_body;
        req_body[L"user_level"] = web::json::value::number(i);
        req_body[L"user_no"] = web::json::value::string(L"NAM_" + std::to_wstring(i));

        // Task_1
        client.request(web::http::methods::POST, L"/post", req_body)

        // Task_2
            .then([](web::http::http_response response)
        {
            return response.extract_json();
        })

        // Task_3
            .then([](web::json::value res_body)
        {
            std::wcout << res_body[L"json"].serialize() + L"\n";
        });
    }

    std::wcout << "Request finished!\n";
    Sleep(10000);

    return 0;
}
