from django.views.generic.base import TemplateView

from .models import Todo

class IndexView(TemplateView):
    template_name = "todo/index.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['todos'] = Todo.objects.all()
        return context
