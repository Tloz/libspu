# libspu
A lib for small project. When you don't want to reinvent the wheel each time and don't want to use a framework.
Therefore you may want to use SmallProjectUtilities

Currently, those modules are supported:

#### Random
- ```int random_int(int min = 0 , int max = RAND_MAX);```
- ```float random_float();```
- ```float random_float(float min, float max);```

#### Base64
- ```std::string base64_encode(std::string const& s, bool url = false);```
- ```std::string base64_encode(unsigned char const*, unsigned int len, bool url = false);```
- ```std::string base64_encode_pem (std::string const& s);```
- ```std::string base64_encode_mime(std::string const& s);```
- ```std::string base64_decode(std::string const& s, bool remove_linebreaks = false);```
