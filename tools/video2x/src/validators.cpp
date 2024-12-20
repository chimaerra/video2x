#include "validators.h"

#include <unordered_set>

void validate_anime4k_shader_name(const StringType &shader_name) {
    static const std::unordered_set<StringType> valid_anime4k_shaders = {
        STR("anime4k-v4-a"),
        STR("anime4k-v4-a+a"),
        STR("anime4k-v4-b"),
        STR("anime4k-v4-b+b"),
        STR("anime4k-v4-c"),
        STR("anime4k-v4-c+a"),
        STR("anime4k-v4.1-gan")
    };
    if (valid_anime4k_shaders.count(shader_name) == 0 && !std::filesystem::exists(shader_name)) {
        throw po::validation_error(
            po::validation_error::invalid_option_value,
            "libplacebo-shader",
            "libplacebo-shader must be one of: anime4k-v4-a, anime4k-v4-a+a, anime4k-v4-b, "
            "anime4k-v4-b+b, anime4k-v4-c, anime4k-v4-c+a, anime4k-v4.1-gan, or a valid file path"
        );
    }
}

void validate_realesrgan_model_name(const StringType &model_name) {
    static const std::unordered_set<StringType> valid_realesrgan_models = {
        STR("realesrgan-plus"), STR("realesrgan-plus-anime"), STR("realesr-animevideov3")
    };
    if (valid_realesrgan_models.count(model_name) == 0) {
        throw po::validation_error(
            po::validation_error::invalid_option_value,
            "realesrgan-model",
            "realesrgan-model must be one of: realesr-animevideov3, realesrgan-plus-anime, "
            "realesrgan-plus"
        );
    }
}

void validate_rife_model_name(const StringType &model_name) {
    static const std::unordered_set<StringType> valid_realesrgan_models = {
        STR("rife"),
        STR("rife-HD"),
        STR("rife-UHD"),
        STR("rife-anime"),
        STR("rife-v2"),
        STR("rife-v2.3"),
        STR("rife-v2.4"),
        STR("rife-v3.0"),
        STR("rife-v3.1"),
        STR("rife-v4"),
        STR("rife-v4.6"),
    };
    if (valid_realesrgan_models.count(model_name) == 0) {
        throw po::validation_error(
            po::validation_error::invalid_option_value,
            "rife-model",
            "RIFE model must be one of: rife, rife-HD, rife-UHD, rife-anime, rife-v2, rife-v2.3, "
            "rife-v2.4, rife-v3.0, rife-v3.1, rife-v4, rife-v4.6"
        );
    }
}
