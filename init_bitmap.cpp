void bitmaps_init(char *arquivo)
{
  BITMAP *chipset;
  chipset = load_bitmap(arquivo, NULL);
  for(int i = 0; i < 27; i++)
  {
    int objeto_x, objeto_y;
    objeto_x = i % 4;
    objeto_y = i / 4;
    skin[i] = create_bitmap(32, 32);
    blit(chipset, skin[i], objeto_x * 32, objeto_y * 32, 0, 0, 32, 32);
  }
  destroy_bitmap(chipset);
}
