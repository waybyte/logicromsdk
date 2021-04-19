#based on https://protips.readthedocs.io/link-roles.html
#some part taken from esp-idf extension link-roles.py

import os
import subprocess
from docutils import nodes

def get_github_rev():
    path = subprocess.check_output(['git', 'rev-parse', '--short', 'HEAD']).strip().decode('utf-8')
    try:
        tag = subprocess.check_output(['git', 'describe', '--exact-match'], stderr=subprocess.DEVNULL).strip().decode('utf-8')
    except subprocess.CalledProcessError:
        tag = None
    if tag:
        return tag
    return path

def setup(app):
    app.add_role('github', autolink('https://github.com/%s'))
    app.add_role('header_src_file', autolink('https://github.com/waybyte/logicromsdk/blob/%s/%s'))
    return {'parallel_read_safe': True, 'parallel_write_safe': True, 'version': '1.0'}

def autolink(pattern):
    def role(name, rawtext, text, lineno, inliner, options={}, content=[]):
        rev = get_github_rev()
        url = pattern % (rev,text,)
        node = nodes.reference(rawtext, text, refuri=url, **options)
        return [node], []
    return role

