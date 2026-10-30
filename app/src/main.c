
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// Get all four LEDs from the devicetree
static const struct gpio_dt_spec led0 =
    GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

static const struct gpio_dt_spec led1 =
    GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);

static const struct gpio_dt_spec led2 =
    GPIO_DT_SPEC_GET(DT_ALIAS(led2), gpios);

static const struct gpio_dt_spec led3 =
    GPIO_DT_SPEC_GET(DT_ALIAS(led3), gpios);

int main(void)
{
    // Check that GPIO controllers are ready
    if (!gpio_is_ready_dt(&led0) ||
        !gpio_is_ready_dt(&led1) ||
        !gpio_is_ready_dt(&led2) ||
        !gpio_is_ready_dt(&led3)) {
        return 0;
    }

    // Configure LEDs as outputs
    gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&led2, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&led3, GPIO_OUTPUT_INACTIVE);


    
    while (1) {
        // Turn on LED0
        gpio_pin_set_dt(&led0, 1);
        k_msleep(250);
        gpio_pin_set_dt(&led0, 0);

        // Turn on LED1
        gpio_pin_set_dt(&led1, 1);
        k_msleep(250);
        gpio_pin_set_dt(&led1, 0);

        // Turn on LED2
        gpio_pin_set_dt(&led2, 1);
        k_msleep(250);
        gpio_pin_set_dt(&led2, 0);

        // Turn on LED3
        gpio_pin_set_dt(&led3, 1);
        k_msleep(250);
        gpio_pin_set_dt(&led3, 0);
    }



    return 0;
}
