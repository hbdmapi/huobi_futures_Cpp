#pragma once

#include <string>
using std::string;

namespace huobi_futures
{
    namespace url_base
    {
        class PublicUrlBuilder
        {
        public:
            PublicUrlBuilder(string host)
            {
                this->host = host;
            }

            string Build(const string &path)
            {
                return "https://" + host + path;
            }

        private:
            string host;
        };
    } // namespace url_base
} // namespace huobi_futures