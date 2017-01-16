﻿
// Event processing
//
// AYX-32 project
// (c) TS-Labs
//
// বসে আছি একা কাঁচা রোদ বিকেলে উদাস

// Store AY BUS event
void put_event(u8 reg, u8 val)
{
  BUS_EVT evt;
  evt.time = EVT_TIM::getCounter();
  evt.reg = reg;
  evt.val = val;
  ay_bus_events.put((u8*)&evt, sizeof(evt));
}

// Process event
void process_event()
{
  // console::print("Event %x %x\n", evt.reg, evt.val);
  is_evt = false;
  event_vec[evt.reg]();
}

// Empty
void ev_() {};

// AY register 0 - channel A tone period LSB
void ev_ay0()
  if (!tone[selected_psg_chip][0].period)
    tone[selected_psg_chip][0].period++;
}
// AY register 1 - channel A tone period MSB
  tone[selected_psg_chip][0].periodh = evt.val;
  if (!tone[selected_psg_chip][0].period)
    tone[selected_psg_chip][0].period++;
}
// AY register 2 - channel B tone period LSB
  tone[selected_psg_chip][1].periodl = evt.val;
  if (!tone[selected_psg_chip][1].period)
    tone[selected_psg_chip][1].period++;
}
// AY register 3 - channel B tone period MSB
  tone[selected_psg_chip][1].periodh = evt.val;
  if (!tone[selected_psg_chip][1].period)
    tone[selected_psg_chip][1].period++;
}
// AY register 4 - channel C tone period LSB
  tone[selected_psg_chip][2].periodl = evt.val;
  if (!tone[selected_psg_chip][2].period)
    tone[selected_psg_chip][2].period++;
}
// AY register 5 - channel C tone period MSB
  tone[selected_psg_chip][2].periodh = evt.val;
  if (!tone[selected_psg_chip][2].period)
    tone[selected_psg_chip][2].period++;
}
// AY register 6 - noise period
  noise[selected_psg_chip].period = evt.val & 31;
  if (!noise[selected_psg_chip].period)
    noise[selected_psg_chip].period++;
}
// AY register 7 - channel mixer
  chan[selected_psg_chip][0].is_tone  = (evt.val &  1) ? false : true;
  chan[selected_psg_chip][1].is_tone  = (evt.val &  2) ? false : true;
  chan[selected_psg_chip][2].is_tone  = (evt.val &  4) ? false : true;
  chan[selected_psg_chip][0].is_noise = (evt.val &  8) ? false : true;
  chan[selected_psg_chip][1].is_noise = (evt.val & 16) ? false : true;
  chan[selected_psg_chip][2].is_noise = (evt.val & 32) ? false : true;
}
// AY register 8 - channel A volume
  if (evt.val & 16)
    chan[selected_psg_chip][0].is_env = true;
  else
  {
    chan[selected_psg_chip][0].is_env = false;
    chan[selected_psg_chip][0].amp = (evt.val & 15) << 1;
  }
}
// AY register 9 - channel B volume
  if (evt.val & 16)
    chan[selected_psg_chip][1].is_env = true;
  else
  {
    chan[selected_psg_chip][1].is_env = false;
    chan[selected_psg_chip][1].amp = (evt.val & 15) << 1;
  }
}
// AY register 10 - channel C volume
  if (evt.val & 16)
    chan[selected_psg_chip][2].is_env = true;
  else
  {
    chan[selected_psg_chip][2].is_env = false;
    chan[selected_psg_chip][2].amp = (evt.val & 15) << 1;
  }
}
// AY register 11 - envelope generator period LSB
  env[selected_psg_chip].periodl = evt.val;

  if (!env[selected_psg_chip].period)
    env[selected_psg_chip].period = 1;
}
// AY register 12 - envelope generator period MSB
  env[selected_psg_chip].periodh = evt.val;

  if (!env[selected_psg_chip].period)
    env[selected_psg_chip].period = 1;
}
// AY register 13 - envelope type
{
}

void ev_volar()
}
{

  init_vtab(selected_psg_chip, 1, 1, evt.val);
}

// Channel C Volume Left
void ev_volcl()
{
  init_vtab(selected_psg_chip, 2, 0, evt.val);
}

// Channel C Volume Right
void ev_volcr()
{
  init_vtab(selected_psg_chip, 2, 1, evt.val);
}


// PSG Chip Select
void ev_psgsel()
{
  selected_psg_chip = (evt.val < psg_chip_num) ? evt.val : (psg_chip_num - 1);
}

// Clock config
// Bus config
  psg_chip_num = lim_chip[config.busctr.psgmul];
  selected_psg_chip = 0;
}

// Amplitude table config
void ev_actrl()
{
  config.ampctr.b = evt.val;
  // +++
}