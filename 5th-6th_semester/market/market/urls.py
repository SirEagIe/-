from django.urls import include, re_path
from django.contrib import admin
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    re_path(r'^admin/', admin.site.urls),
    re_path(r'^cart/', include(('cart.urls', 'cart'), namespace='cart')),
    re_path(r'^orders/', include(('orders.urls', 'orders'), namespace='orders')),
    re_path(r'^', include(('goods.urls', 'goods'), namespace='goods')),
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)