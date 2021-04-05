import Vue from 'vue'
import App from './App.vue'

import { BootstrapVue, IconsPlugin } from 'bootstrap-vue'
import VueApexCharts from 'vue-apexcharts'

// Import Bootstrap an BootstrapVue CSS files (order is important)
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

// Make BootstrapVue available throughout your project
Vue.use(BootstrapVue)
// Optionally install the BootstrapVue icon components plugin

Vue.use(IconsPlugin)
Vue.use(VueApexCharts)

Vue.component('apexchart', VueApexCharts)




Vue.config.productionTip = false

new Vue({
  render: h => h(App),
}).$mount('#app')
