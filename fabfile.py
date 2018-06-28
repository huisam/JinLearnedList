from __future__ import with_statement
from fabric.contrib.console import confirm
from fabric.api import local,settings,abort,run,cd,env
from fabric.colors import red,green,blue
from time import sleep
env.hosts = ['localhost']

def test():
    with settings(warn_only=True):
        result = local("./manage.py test my_app", capture=True)
    if result.failed and not confirm("Tests failed. Continue anyway?"):
        abort("Aborting at user request.")

def new_user(username, admin='no', comment="No comment provided"):
    print("New User (%s): %s" % (username, comment))
    pass

def color():
    print(green("This is green."))

def commit():
    local("git add -A && git commit")

def push():
    local("git push")

def prepare_deploy():
    test()
    commit()
    push()

def hostname():
        run('uname -a')

def ls():
        run('ls')
def deploy():
    code_dir = '/home/ubuntu/jinmine'
    with settings(warn_only=True):
        if run("test -d %s" % code_dir).failed:
            run("git clone https://github.com/huisam/jinmine.git")
            sleep(2)
    with cd(code_dir):
        run("git pull")
        run("cat manage.py") 

def exists(path):
    with settings(warn_only=True):
        return run('test -e %s' % path)
