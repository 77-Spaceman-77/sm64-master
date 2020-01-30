//located in mario_actions_airborne.c
//comment out the play sound found in function act_twirling

s32 act_backflip(struct MarioState *m) {
    if (m->input & INPUT_Z_PRESSED) {
        return set_mario_action(m, ACT_GROUND_POUND, 0);
    }

    play_mario_sound(m, SOUND_ACTION_TERRAIN_JUMP, SOUND_MARIO_YAH_WAH_HOO);
    common_air_action_step(m, ACT_BACKFLIP_LAND, MARIO_ANIM_BACKFLIP, 0);
    m->vel[1] += 2.0f; // increases height of the backflip action
    if (++m->actionTimer == 23) { //backflip action plays until it reaches its set value
        return set_mario_action(m, ACT_TWIRLING, 0); //twirling action loads
    }
    return FALSE;
}
