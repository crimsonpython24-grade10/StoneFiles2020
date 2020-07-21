from django.db import models
from django.utils.translation import gettext_lazy as _


class Todo(models.Model):
    level_choices = [
        ('important', 'Important'),
        ('normal', 'Normal'),
        ('unimportant', 'Not important')
    ]
    title = models.CharField(_('title'), max_length=50)
    desc = models.TextField(_('description'), max_length=500, blank=True)
    level = models.CharField(_('importancy'), max_length=20, choices=level_choices)
    created = models.DateTimeField(_('date created'), auto_now_add=True)

    def __str__(self):
        return self.title
