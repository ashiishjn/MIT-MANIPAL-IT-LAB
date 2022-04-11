from django.http import HttpResponse, HttpResponseRedirect
from django.template import loader
from django.urls import reverse
from .models import Inventory

def index(request):
  mymembers = Inventory.objects.all().values()
  template = loader.get_template('index.html')
  context = {
    'mymembers': mymembers,
  }
  return HttpResponse(template.render(context, request))

def add(request):
  template = loader.get_template('add.html')
  return HttpResponse(template.render({}, request))

def addrecord(request):
  x = request.POST['i_name']
  y = request.POST['qty']
  member = Inventory(Itemname=x, Quantity=y)
  member.save()
  return HttpResponseRedirect(reverse('index'))

def delete(request, id):
  member = Inventory.objects.get(id=id)
  member.delete()
  return HttpResponseRedirect(reverse('index'))

def update(request, id):
  mymember = Inventory.objects.get(id=id)
  template = loader.get_template('update.html')
  context = {
    'mymember': mymember,
  }
  return HttpResponse(template.render(context, request))

def updaterecord(request, id):
  first = request.POST['item_name']
  last = request.POST['Quan']
  member = Inventory.objects.get(id=id)
  member.Itemname = first
  member.Quantity = last
  member.save()
  return HttpResponseRedirect(reverse('index'))