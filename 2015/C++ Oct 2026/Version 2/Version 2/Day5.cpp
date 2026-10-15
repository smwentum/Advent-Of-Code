#include "Day5.h"

#include<openssl/md5.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <memory>

#include <openssl/evp.h>
#include <cstdio>


using std::cout; 
using std::endl;



using namespace std;

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <memory>
#include <openssl/evp.h>

// Helper structure for automated resource cleanup (RAII)
struct EVPContextDeleter {
    void operator()(EVP_MD_CTX* ctx) const {
        EVP_MD_CTX_free(ctx);
    }
};

std::string compute_md5(const std::string& input) {
    // Create and initialize the context using a smart pointer for safe cleanup
    std::unique_ptr<EVP_MD_CTX, EVPContextDeleter> context(EVP_MD_CTX_new());
    if (!context) {
        throw std::runtime_error("Failed to create OpenSSL EVP context.");
    }

    // Initialize the digest operation with MD5
    if (EVP_DigestInit_ex(context.get(), EVP_md5(), nullptr) != 1) {
        throw std::runtime_error("Failed to initialize MD5 digest.");
    }

    // Pass the string data to be hashed
    if (EVP_DigestUpdate(context.get(), input.c_str(), input.length()) != 1) {
        throw std::runtime_error("Failed to update MD5 digest.");
    }

    // Allocate buffer for the result (MD5 produces a 16-byte/128-bit hash)
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len = 0;

    // Finalize the digest and retrieve the result
    if (EVP_DigestFinal_ex(context.get(), hash, &hash_len) != 1) {
        throw std::runtime_error("Failed to finalize MD5 digest.");
    }

    // Convert the raw binary array into a readable hexadecimal string
    std::stringstream hex_stream;
    for (unsigned int i = 0; i < hash_len; ++i) {
        hex_stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return hex_stream.str();
}

void Day5Part1()
{
    int i{ 0 };
    int count{ 0 };
    cout << "Day 5 part 1: "; 
    while (count < 8)
    {
        std::string s{ compute_md5("abc" +std::to_string(i) ) };
        //cout << "abc" << std::to_string(i) <<": " << s << endl;
        i++;
        if (s.starts_with("00000"))
        {
            cout << s[5];
            count++; 
        }
    }
    cout << endl; 
}
void Day5Part2()
{

}