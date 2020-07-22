from django.views.generic.base import TemplateView

from rest_framework import viewsets

from .models import Todo
from .serializers import TodoSerializer


class IndexView(TemplateView):
    template_name = "todo/index.html"


class TodoViewSet(viewsets.ModelViewSet):
    queryset = Todo.objects.get_queryset().order_by('id')
    serializer_class = TodoSerializer
from django.views import View
from django.views.decorators.csrf import ensure_csrf_cookie
from django.utils.decorators import method_decorator
from django.shortcuts import render
from django.http import JsonResponse

from rest_framework import viewsets

from .models import Todo
from .serializers import TodoSerializer


# @method_decorator(ensure_csrf_cookie, name='dispatch')
class IndexView(View):
    template_name = "todo/index.html"

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name)

    def post(self, request, *args, **kwargs):
        if 'delete' in request.POST.get("method"):
            Todo.objects.filter(id=request.POST.get("keyid")).delete()
            return JsonResponse({'success': True})
        else:
            return JsonResponse({'success': False})


class TodoViewSet(viewsets.ModelViewSet):
    queryset = Todo.objects.get_queryset().order_by('id')
    serializer_class = TodoSerializer
