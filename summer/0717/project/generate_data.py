# Don't change the format. Order matters!

import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'project.settings')

import django
django.setup()

import random
from faker import Faker

from todo.models import Todo


fakegen = Faker()

def populate(N = 10):
    for entry in range(N):
        fake_tmp = fakegen.catch_phrase()
        levels = ['important', 'normal', 'unimportant']

        fake_title = fake_tmp if len(fake_tmp) <= 50 else (fake_tmp[:47] + '...')
        fake_desc = fakegen.sentence(nb_words=70)
        fake_level = levels[random.randint(0, 2)]

        todo_item = Todo.objects.get_or_create(title=fake_title, desc=fake_desc, level=fake_level)

if __name__ == '__main__':
    print('Populating data...')
    populate(20)
    print('Populating complete')
