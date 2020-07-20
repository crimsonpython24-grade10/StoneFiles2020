from .models import Todo

from rest_framework import serializers


class TodoSerializer(serializers.BaseSerializer):
    level_choices = [
        ('important', 'Important'),
        ('normal', 'Normal'),
        ('unimportant', 'Not important')
    ]
    title = serializers.CharField(max_length=150, trim_whitespace=True)
    desc = serializers.CharField(max_length=500, allow_blank=True)
    level = serializers.ChoiceField(choices=level_choices)
    created = serializers.DateTimeField()
