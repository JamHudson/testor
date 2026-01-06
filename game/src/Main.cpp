#include <bn_backdrop.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_dot.h"

int main()
{
    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 31, 0));

    auto dot = bn::sprite_items::dot.create_sprite(0, 0);

    bn::fixed speed = 1.5;

    while (true)
    {
        dot.set_horizontal_scale(1);
        dot.set_vertical_scale(1);
        if (bn::keypad::left_held())
        {
            dot.set_x(dot.x() - speed);
        }
        if (bn::keypad::right_held())
        {
            dot.set_x(dot.x() + speed);
        }
        if (bn::keypad::up_held())
        {
            dot.set_y(dot.y() - speed);
            dot.set_vertical_scale(0.75);
            dot.set_horizontal_scale(1.25);
        }
        if (bn::keypad::down_held())
        {
            dot.set_y(dot.y() + speed);
            dot.set_vertical_scale(1.25);
            dot.set_horizontal_scale(0.75);
        }
        bn::core::update();
    }
}