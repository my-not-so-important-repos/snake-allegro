void bitmaps_init(){
  BITMAP *chipset;
  PALETTE paleta;

  chipset = load_bitmap("skin\\chip2.bmp", paleta);
  set_palette(paleta);

  chao                     = create_bitmap(32, 32);
  parede_cruz              = create_bitmap(32, 32);
  parede_horizontal        = create_bitmap(32, 32);
  parede_vertical          = create_bitmap(32, 32);

  parede_inferior_direita  = create_bitmap(32, 32);
  parede_inferior_esquerda = create_bitmap(32, 32);
  parede_superior_direita  = create_bitmap(32, 32);
  parede_superior_esquerda = create_bitmap(32, 32);

  parede_t_baixo           = create_bitmap(32, 32);
  parede_t_cima            = create_bitmap(32, 32);
  parede_t_direita         = create_bitmap(32, 32);
  parede_t_esquerda        = create_bitmap(32, 32);

  cabeca_cima               = create_bitmap(32, 32);
  cabeca_baixo              = create_bitmap(32, 32);
  cabeca_esquerda           = create_bitmap(32, 32);
  cabeca_direita            = create_bitmap(32, 32);

  cauda_cima                = create_bitmap(32, 32);
  cauda_baixo               = create_bitmap(32, 32);
  cauda_esquerda            = create_bitmap(32, 32);
  cauda_direita             = create_bitmap(32, 32);

  vertebra_inferior_direita  = create_bitmap(32, 32);
  vertebra_inferior_esquerda = create_bitmap(32, 32);
  vertebra_superior_direita  = create_bitmap(32, 32);
  vertebra_superior_esquerda = create_bitmap(32, 32);

  vertebra_horizontal = create_bitmap(32, 32);
  vertebra_vertical   = create_bitmap(32, 32);
  maca                = create_bitmap(32, 32);

  blit(chipset, chao,               0,  0, 0, 0, 32, 32);
  blit(chipset, parede_cruz,       32,  0, 0, 0, 32, 32);
  blit(chipset, parede_horizontal, 64,  0, 0, 0, 32, 32);
  blit(chipset, parede_vertical,   96,  0, 0, 0, 32, 32);

  blit(chipset, parede_inferior_direita,   0, 32, 0, 0, 32, 32);
  blit(chipset, parede_inferior_esquerda, 32, 32, 0, 0, 32, 32);
  blit(chipset, parede_superior_direita,  64, 32, 0, 0, 32, 32);
  blit(chipset, parede_superior_esquerda, 96, 32, 0, 0, 32, 32);

  blit(chipset, parede_t_baixo,     0, 64, 0, 0, 32, 32);
  blit(chipset, parede_t_cima,     32, 64, 0, 0, 32, 32);
  blit(chipset, parede_t_direita,  64, 64, 0, 0, 32, 32);
  blit(chipset, parede_t_esquerda, 96, 64, 0, 0, 32, 32);

  blit(chipset, cabeca_cima,      0, 96, 0, 0, 32, 32);
  blit(chipset, cabeca_baixo,    32, 96, 0, 0, 32, 32);
  blit(chipset, cabeca_esquerda, 64, 96, 0, 0, 32, 32);
  blit(chipset, cabeca_direita,  96, 96, 0, 0, 32, 32);

  blit(chipset, cauda_cima,      0, 128, 0, 0, 32, 32);
  blit(chipset, cauda_baixo,    32, 128, 0, 0, 32, 32);
  blit(chipset, cauda_esquerda, 64, 128, 0, 0, 32, 32);
  blit(chipset, cauda_direita,  96, 128, 0, 0, 32, 32);

  blit(chipset, vertebra_inferior_direita,   0, 160, 0, 0, 32, 32);
  blit(chipset, vertebra_inferior_esquerda, 32, 160, 0, 0, 32, 32);
  blit(chipset, vertebra_superior_direita,  64, 160, 0, 0, 32, 32);
  blit(chipset, vertebra_superior_esquerda, 96, 160, 0, 0, 32, 32);

  blit(chipset, vertebra_horizontal, 0, 192, 0, 0, 32, 32);
  blit(chipset, vertebra_vertical,  32, 192, 0, 0, 32, 32);
  blit(chipset, maca,               64, 192, 0, 0, 32, 32);

  destroy_bitmap(chipset); // para liberar mem¢ria
}
