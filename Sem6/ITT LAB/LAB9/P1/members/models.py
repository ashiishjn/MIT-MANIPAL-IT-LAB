from django.db import models

class Inventory(models.Model):
  Itemname = models.CharField(max_length=255)
  Quantity = models.CharField(max_length=255)